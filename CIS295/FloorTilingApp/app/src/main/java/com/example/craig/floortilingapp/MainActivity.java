package com.example.craig.floortilingapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {

    int tileSizeOne = 12;
    int tileSizeTwo = 18;
    DecimalFormat form = new DecimalFormat("##.##");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button submitBtn = findViewById(R.id.btnSubmit);
        final RadioButton sizeOneBtn = findViewById(R.id.btnSize12);
        final RadioButton sizeTwoBtn = findViewById(R.id.btnSize18);
        final EditText sqFtEditTxt = findViewById(R.id.SqFtEditText);
        final TextView resultsTxt = findViewById(R.id.textResult);

        submitBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String ResultsString = "";
                double sqft = Double.parseDouble(sqFtEditTxt.getText().toString());
                if(sizeOneBtn.isChecked()){
                    ResultsString = form.format(sqft/(tileSizeOne*tileSizeOne));
                }else if (sizeTwoBtn.isChecked()){
                    ResultsString = form.format(sqft/(tileSizeTwo*tileSizeTwo));
                }else{
                    ResultsString = "Choose a tile size first!";
                }
                resultsTxt.setText(ResultsString);
            }
        });
    }
}
