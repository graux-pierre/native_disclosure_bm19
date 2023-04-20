package lu.uni.graux.bm19;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.provider.Settings;
import android.widget.TextView;

import lu.uni.graux.bm19.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    private char[] imei;
    private char[] notImei;

    static {
        System.loadLibrary("bm19");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        TextView tv = binding.sampleText;

        this.imei = Settings.Secure.getString(this.getApplicationContext().getContentResolver(), Settings.Secure.ANDROID_ID).toCharArray();

        this.notImei = "Hello".toCharArray();
        this.arrayCopyUsingJNI();
        tv.setText(String.valueOf(this.notImei));
    }

    public native void arrayCopyUsingJNI();
}