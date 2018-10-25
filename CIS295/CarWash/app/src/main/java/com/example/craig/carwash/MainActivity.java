package com.example.craig.carwash;

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

    double priceWashNoDiscount = 10.99;
    double priceWashDiscount = 8.99;
    double priceComboNoDiscount = 15.99;
    double priceComboDiscount = 12.99;

    int numWashes;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final RadioButton btnCombo = findViewById(R.id.rdoCombo);
        final RadioButton btnWash = findViewById(R.id.rdoExteriorOnly);

        final EditText txtInput = findViewById(R.id.txtInput);
        final TextView txtResult = findViewById(R.id.txtResult);

        Button btnCalc = findViewById(R.id.btnCalc);
        btnCalc.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                numWashes = Integer.parseInt(txtInput.getText().toString());
                double totalCost;
                if (numWashes<12){
                    Toast.makeText(MainActivity.this, "Order 12+ washes for a discount", Toast.LENGTH_SHORT).show();
                }
                if (btnCombo.isChecked()) {
                    totalCost = (numWashes >= 12 ? numWashes * priceComboDiscount : numWashes * priceComboNoDiscount);
                } else if (btnWash.isChecked()) {
                    totalCost = (numWashes >= 12 ? numWashes * priceWashDiscount : numWashes * priceWashNoDiscount);
                }else{
                    return;
                }

                txtResult.setText(DecimalFormat.getCurrencyInstance().format(totalCost));

            }
        });
    }
}
