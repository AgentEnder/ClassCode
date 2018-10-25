package com.example.craig.chapter10bookwork;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;

public class TweenActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tween);
        ((ImageView) findViewById(R.id.imgTween)).startAnimation(AnimationUtils.loadAnimation(this, R.anim.rotation));
    }
}
