package com.example.craig.chapter11;

import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.text.DecimalFormat;

public class Payment extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_payment);
        TextView monthlyPayment = findViewById(R.id.txtMonthlyPayment);
        ImageView image = findViewById(R.id.numYearsImg);
        SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        int intYears = sharedPreferences.getInt("key1",0);
        float floatAmt = sharedPreferences.getFloat("key2", 0);
        float floatInterest = sharedPreferences.getFloat("key3", 0);

        float decMonthlyPayment = (floatAmt*(1+(floatInterest*intYears)))/(12*intYears);
        monthlyPayment.setText(DecimalFormat.getCurrencyInstance().format(decMonthlyPayment));
        switch (intYears){
            case 3:
                image.setImageResource(R.drawable.three);
                break;
            case 4:
                image.setImageResource(R.drawable.four);
                break;
            case 5:
                image.setImageResource(R.drawable.five);
                break;
            default:
                monthlyPayment.setText("Enter 3, 4, or 5 years.");
                break;
        }
    }
}
