# protobuf_dev

## protobuf 调试 （Linux）

> 调试前需要先执行source setup.sh

> java 部分最好使用IntelliJ IDEA打开执行

> java protobuf demo,用来encode 来自java的protobuf数据，以Binery方式写入./protobuf_javanano/JavaNanoTest/test.bin

> 代码路径：

> ./protobuf_javanano/JavaNanoTest/src/Main.java

> protobuf c code:

来自 [github nanopb](https://github.com/nanopb/nanopb) 使用版本 nanopb-0.3.4-linux-x86

> protobuf_nano_c/nanopb/examples/watch_proto_test

> make & ./watch_face_pb_test 命令来decode 来自文件 ./protobuf_javanano/JavaNanoTest/test.bin 的 字节流

> 修改./protobuf_nano_c/nanopb/examples/watch_proto_testt/watch_widget_info.proto

> make 时会生成对应的java文件到 ./protobuf_javanano/JavaNanoTest/src/


> Note：protoc 需要支持 --javanano_out参数，3.0.0 验证可用，使用protoc --version检查版本号
