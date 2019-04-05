# Include the nanopb provided Makefile rules
include ../../extra/nanopb.mk

# Compiler flags to enable all warnings & debug info
CFLAGS = -Wall -Werror -g -O0
CFLAGS += -I$(NANOPB_DIR)
CFLAGS += -D NANO_BUF_FILE=\"$(TEST_NANO_BIN_PATH)\"

# C source code files that are required
CSRC  = watch_face_pb_test.c                   # The main program
CSRC += watch_widget_info.pb.c                # The compiled protocol definition
CSRC += $(NANOPB_DIR)/pb_encode.c  # The nanopb encoder
CSRC += $(NANOPB_DIR)/pb_decode.c  # The nanopb decoder
CSRC += $(NANOPB_DIR)/pb_common.c  # The nanopb common parts

# Build rule for the main program
watch_face_pb_test: $(CSRC)
	$(CC) $(CFLAGS) -owatch_face_pb_test $(CSRC)

# Build rule for the protocol
watch_widget_info.pb.c: watch_widget_info.proto
	echo $(PROTOC)
	echo "java nano out path:"$(JAVANANO_OUT_PATH)
	$(PROTOC) $(PROTOC_OPTS) --nanopb_out=. watch_widget_info.proto
	$(PROTOC) $(PROTOC_OPTS) --javanano_out=enum_style=java,optional_field_style=accessors,parcelable_messages=true:$(JAVANANO_OUT_PATH) watch_widget_info.proto
