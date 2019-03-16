import com.google.protobuf.nano.CodedOutputByteBufferNano;
import com.huami.watch.sensorhub.nano.WatchWidgetInfo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello Proto Nano!");
        WatchWidgetInfo.WatchFaceInfo mWatchFaceInfo = new WatchWidgetInfo.WatchFaceInfo();

        mWatchFaceInfo.circleStepProgresses = new WatchWidgetInfo.QuarterCircleStepProgress[4];
        int j;
        for(j = 0; j < 4 ; j++) {
            mWatchFaceInfo.circleStepProgresses[j] = new WatchWidgetInfo.QuarterCircleStepProgress();
        }
        mWatchFaceInfo.circleStepProgresses[0].dataType = 1;
        mWatchFaceInfo.circleStepProgresses[0].icon = -1;
        mWatchFaceInfo.circleStepProgresses[0].shortText = "3K";
        mWatchFaceInfo.circleStepProgresses[0].progress = 0.6f;
        mWatchFaceInfo.circleStepProgresses[0].step = 37;

        mWatchFaceInfo.circleStepProgresses[1].dataType = 4;
        mWatchFaceInfo.circleStepProgresses[1].icon = -1;
        mWatchFaceInfo.circleStepProgresses[1].shortText = "488";
        mWatchFaceInfo.circleStepProgresses[1].progress = 0.6f;
        mWatchFaceInfo.circleStepProgresses[1].step = 37;

        mWatchFaceInfo.circleStepProgresses[2].dataType = 14;
        mWatchFaceInfo.circleStepProgresses[2].icon = -1;
        mWatchFaceInfo.circleStepProgresses[2].shortText = "7.45H";
        mWatchFaceInfo.circleStepProgresses[2].progress = 0.6f;
        mWatchFaceInfo.circleStepProgresses[2].step = 37;

        mWatchFaceInfo.circleStepProgresses[3].dataType = 11;
        mWatchFaceInfo.circleStepProgresses[3].icon = -1;
        mWatchFaceInfo.circleStepProgresses[3].shortText = "80%";
        mWatchFaceInfo.circleStepProgresses[3].progress = 0.8f;
        mWatchFaceInfo.circleStepProgresses[3].step = 37;


        System.out.println("bytes len:" + mWatchFaceInfo.getSerializedSize());
        byte[] flatArray = new byte[mWatchFaceInfo.getSerializedSize()];
        CodedOutputByteBufferNano output = CodedOutputByteBufferNano.newInstance(flatArray);
        try {
            mWatchFaceInfo.writeTo(output);
        } catch (IOException e) {
            e.printStackTrace();
        }

        File file = new File("test.bin");
        try {
            FileOutputStream fout = new FileOutputStream(file);
            fout.write(flatArray);
            fout.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
