
#!/bin/bash
cd ./protobuf_javanano/JavaNanoTest/src
export JAVANANO_OUT_PATH=`pwd`
echo "JAVANANO_OUT_PATH:" $JAVANANO_OUT_PATH
cd -
cd ./protobuf_javanano/JavaNanoTest
export TEST_NANO_BIN_PATH=`pwd`/test.bin
echo "TEST_NANO_BIN_PATH:" $TEST_NANO_BIN_PATH
cd -
if [ "$(uname)"="Darwin" ];then
    cd ./protobuf_nano_c/nanopb-0.3.9.3-macosx-x86/generator-bin
elif [ "$(expr substr $(uname -s) 1 5)"="Linux" ];then
    cd ./protobuf_nano_c/nanopb-0.3.9.3-linux-x86/generator-bin
fi
export PROTC_PATH=`pwd`
echo "PROTC_PATH:" $PROTC_PATH
cd -
export PATH=$PATH:$PROTC_PATH