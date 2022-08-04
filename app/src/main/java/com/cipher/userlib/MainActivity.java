package com.cipher.userlib;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.cipher.userlib.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'userlib' library on application startup.
    static {
        System.loadLibrary("userlib");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText("test");
    }

    /**
     * A native method that is implemented by the 'userlib' native library,
     * which is packaged with this application.
     */
}