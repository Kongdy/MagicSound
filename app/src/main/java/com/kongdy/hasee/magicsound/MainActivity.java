package com.kongdy.hasee.magicsound;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.kongdy.hasee.magicsound.voicehelp.Voicer;

import java.io.File;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    public void btnClick(View v) {
        String path = Environment.getExternalStorageDirectory().getAbsolutePath()+ File.separatorChar+"testSound.wma";
        switch (v.getId()) {
            case R.id.btn_org:
                toast("原声");
                break;
            case R.id.btn_girl:
                toast("女声");
                Voicer.fix(path,Voicer.MODE_GRIL);
                break;
        }
    }

    private void toast(CharSequence text) {
        Toast.makeText(this,text,Toast.LENGTH_SHORT).show();
    }

}
