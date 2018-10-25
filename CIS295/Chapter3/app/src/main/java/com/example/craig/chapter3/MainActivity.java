package com.example.craig.chapter3;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

import java.text.DecimalFormat;

public class MainActivity extends AppCompatActivity {
    EditText tickets;
    Spinner group;
    Button cost;
    double costPerTicket = 79.99;
    int numberOfTickets;
    double totalCost;
    String groupChoice;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        setContentView(R.layout.activity_main);
    }

    public void findCost(View view) {
        tickets = (EditText)findViewById(R.id.txtTickets);
        group = (Spinner)findViewById(R.id.spinner);
        cost = (Button)findViewById(R.id.btnCost);
        TextView result = ((TextView)findViewById(R.id.txtResult));
        numberOfTickets = Integer.parseInt(tickets.getText().toString());
        totalCost = costPerTicket*numberOfTickets;
        DecimalFormat currency = new DecimalFormat("$###,###.##");
        groupChoice = group.getSelectedItem().toString();
        result.setText("Cost for " + groupChoice + " is " + currency.format(totalCost));
    }
}
