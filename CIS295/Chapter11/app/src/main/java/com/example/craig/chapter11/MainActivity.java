package com.example.craig.chapter11;

import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    int intYears;
    double decLoan;
    double decInterest;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText years = findViewById(R.id.numYears);
        final EditText loanAmount = findViewById(R.id.loanAmt);
        final EditText interestRate = findViewById(R.id.interestRate);
        Button button = findViewById(R.id.btnPayment);
        final SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                intYears = Integer.parseInt(years.getText().toString());
                decLoan = Double.parseDouble(loanAmount.getText().toString());
                decInterest = Double.parseDouble(interestRate.getText().toString());
                SharedPreferences.Editor edit = sharedPreferences.edit();
                edit.putInt("key1", intYears);
                edit.putFloat("key2", (float)decLoan);
                edit.putFloat("key3", (float)decInterest);
                edit.commit();
                startActivity(new Intent(MainActivity.this, Payment.class));
            }
        });
    }
}
