package catolicasc.org.br.roboticarmcontrol;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        TextView text = findViewById(R.id.dataReceived);

        text.setText("Lorem ipsum \r\n  dolor sit amet, consectetur adipiscing elit. In ac dolor aliquet, porta massa id, interdum risus. Nam mollis, dolor sit amet aliquet aliquam, elit mi feugiat nisi, at consectetur elit mi congue sem. In aliquet odio quis convallis commodo. Suspendisse eget rutrum ante. Mauris scelerisque, erat sed sagittis fringilla, mi quam luctus massa, sit amet finibus est diam pulvinar turpis. Quisque id auctor leo. Etiam sagittis sed dolor in aliquet. Aliquam at eros eros. Praesent luctus sit amet nisl non facilisis.");


        text.setMovementMethod(new ScrollingMovementMethod());
    }
}
