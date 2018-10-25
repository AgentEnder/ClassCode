package com.example.craig.Case6_1;

import android.media.MediaPlayer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    int playing = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnUkulele = findViewById(R.id.playUkuleleBtn);
        Button btnDrums = findViewById(R.id.playDrumBtn);

        final MediaPlayer ukulelePlayer = MediaPlayer.create(this, R.raw.bagpipes);
        final MediaPlayer drumsPlayer = MediaPlayer.create(this, R.raw.jig);

        btnUkulele.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (playing == 0) {
                    ukulelePlayer.start();
                    playing = 1;
                }else{
                    playing = 0;
                    ukulelePlayer.pause();
                }
            }
        });

        btnDrums.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (playing==0){
                    drumsPlayer.start();
                    playing = 1;
                }else{
                    drumsPlayer.pause();
                    playing = 0;
                }
            }
        });
    }
}
