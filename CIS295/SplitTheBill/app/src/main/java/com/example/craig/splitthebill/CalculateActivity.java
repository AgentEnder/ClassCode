package com.example.craig.splitthebill;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.text.DecimalFormat;

public class CalculateActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calculate);
    }

    public void calcTotal(View view) {
        final double tipPercent = 0.18;
        EditText priceEntryWidget = findViewById(R.id.txtBill);
        double price = Double.parseDouble(priceEntryWidget.getText().toString());
        EditText peopleEntryWidget = findViewById(R.id.txtNumPeople);
        int people = Integer.parseInt(peopleEntryWidget.getText().toString());
        double tip = price*tipPercent;
        DecimalFormat currencyFormat = new DecimalFormat("$###,###.##");
        TextView displayView = findViewById(R.id.txtDisplay);
        displayView.setText("Total Cost: " + currencyFormat.format(price+tip) + "\n" + "Tip Amount: " + currencyFormat.format(tip) + "\n" + "Price per person: " + currencyFormat.format((price+tip)/people));
    }
}
