#include <stdio.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "simple.pb.h"

int main()
{
    /* This is the buffer where we will store our message. */
    uint8_t buffer[128];
    size_t message_length;
    bool status;
    
    /* Encode our message */
    {
        /* Allocate space on the stack to store the message data.
         *
         * Nanopb generates simple struct definitions for all the messages.
         * - check out the contents of simple.pb.h!
         * It is a good idea to always initialize your structures
         * so that you do not have garbage data from RAM in there.
         */
        SimpleMessage message = SimpleMessage_init_zero;
        
        /* Create a stream that will write to our buffer. */
        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
        
        /* Fill in the lucky number */
        message.lucky_number = 13;
        //message.text.funcs.decode = &read_string;
        //message.text.arg = "default";
        
        /* Now we are ready to encode the message! */
        status = pb_encode(&stream, SimpleMessage_fields, &message);
        message_length = stream.bytes_written;
        printf("message_length:%ld\n",message_length);
        
        /* Then just check for any errors.. */
        if (!status)
        {
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }
    }
    
    /* Now we could transmit the message over network, store it in a file or
     * wrap it to a pigeon's leg.
     */

    /* But because we are lazy, we will just decode it immediately. */
    
    {
        /* Allocate space for the decoded message. */
        SimpleMessage message = SimpleMessage_init_zero;
        int length;
        FILE* inputFile = fopen("/home/workspace/sandbox/demos/java/test.bin","rb");
        if(inputFile == NULL) {
            printf("file open failed !\n");
            return 0;
        }
        fseek(inputFile, 0, SEEK_END);
        length = ftell(inputFile);
        printf("file contains %d bytes",length);
        rewind(inputFile);
        length = fread(buffer, 1, length, inputFile);
        buffer[length] = '\0';
        fclose(inputFile);

        if(length != 0) {
            printf("read %d bytes\n",length);
        } else {
            printf("read nothing\n");
        }
        
        /* Create a stream that reads from the buffer. */
        pb_istream_t stream = pb_istream_from_buffer(buffer, length);
        
        /* Now we are ready to decode the message. */
        status = pb_decode(&stream, SimpleMessage_fields, &message);
        
        /* Check for errors... */
        if (!status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }
        
        /* Print the data contained in the message. */
        printf("Your lucky number was %d!\n", message.lucky_number);
        printf("Text is :%s\n",message.text);
    }
    
    return 0;
}

/*
static bool read_string(pb_istream_t *stream, const pb_field_t *field, void **arg)
{
    uint8_t buf[20] = {0};
    size_t len = stream->bytes_left;
    
    if (len > sizeof(buf) - 1 || !pb_read(stream, buf, len))
        return false;
    
    //TEST(strcmp((char*)buf, *arg) == 0);
    return true;
}
*/