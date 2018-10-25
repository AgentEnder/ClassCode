package com.example.craig.chapter10bookwork;

import android.content.Intent;
import android.graphics.drawable.AnimationDrawable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
    AnimationDrawable lightsAnimation;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ImageView imgFrame = findViewById(R.id.imgLights);
        imgFrame.setBackgroundResource(R.drawable.animation);
        lightsAnimation = (AnimationDrawable) imgFrame.getBackground();
        Button btnStart = findViewById(R.id.btnStart);
        Button btnStop = findViewById(R.id.btnStop);
        btnStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                lightsAnimation.start();
            }
        });
        btnStop.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                lightsAnimation.stop();
                startActivity(new Intent(MainActivity.this, TweenActivity.class));
            }
        });
    }
}
