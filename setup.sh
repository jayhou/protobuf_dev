
#!/bin/bash
cd ./protobuf_javanano/JavaNanoTest/src
export JAVANANO_OUT_PATH=`pwd`
cd -
cd ./protobuf_javanano/JavaNanoTest
export TEST_NANO_BIN_PATH=`pwd`/test.bin
cd -
cd ./protobuf_nano_c/nanopb-0.3.4-linux-x86/generator-bin
export PROTC_PATH=`pwd`
cd -
export PATH=$PATH:$PROTC_PATH
echo $TEST_NANO_BIN_PATH
echo "protc path:" $PROTC_PATH