package com.example.craig.chp10_golf;

import android.content.Context;
import android.graphics.drawable.AnimationDrawable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
    AnimationDrawable frame;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final ImageView animFrame = findViewById(R.id.AnimFrame);
        animFrame.setBackgroundResource(R.drawable.frame);
        frame = (AnimationDrawable)animFrame.getBackground();
        Button start = findViewById(R.id.startBtn);
        Button stop = findViewById(R.id.stopBtn);
        final Context context = this;
        start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                frame.start();
            }
        });
        stop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                animFrame.startAnimation(AnimationUtils.loadAnimation(context, R.anim.rotate));
            }
        });
    }
}
