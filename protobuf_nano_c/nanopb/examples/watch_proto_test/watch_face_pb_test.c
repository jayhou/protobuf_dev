#include <stdio.h>
#include <pb_encode.h>
#include <pb_decode.h>
#include "watch_widget_info.pb.h"

int main()
{
    /* This is the buffer where we will store our message. */
    uint8_t buffer[128];
    bool status;
    
    {
        /* Allocate space for the decoded message. */
        WatchFaceInfo watchFaceInfo = WatchFaceInfo_init_zero;
        // QuarterCircleStepProgress stepProgress = QuarterCircleStepProgress_init_zero;
        //SimpleMessage message = SimpleMessage_init_zero;

        int length;
        FILE* inputFile = fopen(NANO_BUF_FILE,"rb");
        if(inputFile == NULL) {
            printf("file open failed !\n");
            return 0;
        }
        fseek(inputFile, 0, SEEK_END);
        length = ftell(inputFile);
        printf("file contains %d bytes\n",length);
        rewind(inputFile);
        length = fread(buffer, 1, length, inputFile);
        buffer[length] = '\0';
        fclose(inputFile);

        if(length != 0) {
            printf("read %d bytes\n",length);
        } else {
            printf("read nothing \n");
        }

        pb_istream_t stream = pb_istream_from_buffer(buffer, length);

        status = pb_decode(&stream, WatchFaceInfo_fields, &watchFaceInfo);
        
        /* Check for errors... */
        if (!status)
        {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }
        
        /*
        printf("QuarterCircelStepProgresse: [dataType:%d]-[icon:%d]-[shortText:%s]-[progress:%f]-[step:%d]\n"
                                        ,stepProgress.dataType,stepProgress.icon,stepProgress.shortText,stepProgress.progress,stepProgress.step);
        */

        
        int i;
        for(i = 0; i < 4; i++) {
            printf("WatchFaceInfo.circleStepProgress[%d]: [dataType:%d]-[icon:%d]-[shortText:%s]-[progress:%f]-[step:%d]\n"
                                        ,i,watchFaceInfo.circleStepProgresses[i].dataType,watchFaceInfo.circleStepProgresses[i].icon,watchFaceInfo.circleStepProgresses[i].shortText,watchFaceInfo.circleStepProgresses[i].progress,watchFaceInfo.circleStepProgresses[i].step);
        }
    
        //printf("Your lucky number was %d!\n", message.lucky_number);
        //printf("Text is :%s\n",message.text);
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