package com.example.craig.powertools_exam2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {

    double WasherCost = 55.99;
    double TillerCost = 68.99;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final TextView textResult = findViewById(R.id.ResultsTxt);
        final RadioButton WasherRdo = findViewById(R.id.WasherRdo);
        final RadioButton TillerRdo = findViewById(R.id.TillerRdo);
        final EditText DayTxt = findViewById(R.id.DayInput);
        Button SubmitBtn = findViewById(R.id.SubmitBtn);

        SubmitBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                double price = (double)Integer.parseInt(DayTxt.getText().toString());
                if(price > 7){
                    Toast.makeText(MainActivity.this, "You can not rent a tool more than 7 days!", Toast.LENGTH_LONG).show();
                    return;
                }
                if(WasherRdo.isChecked()){
                    price*=WasherCost;
                }else if(TillerRdo.isChecked()){
                    price*=TillerCost;
                }
                textResult.setText(DecimalFormat.getCurrencyInstance().format(price));
            }
        });
    }
}

