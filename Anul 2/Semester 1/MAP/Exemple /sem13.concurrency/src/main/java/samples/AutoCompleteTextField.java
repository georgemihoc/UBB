package samples;

import java.util.HashSet;
import javafx.event.EventHandler;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;

public class AutoCompleteTextField extends TextField {


    private HashSet<String> autoCompleteList = new HashSet<String>();
    private int completionAfterxChars;


    public AutoCompleteTextField(HashSet<String> autoCompleteList, int completionAfterxChars){
        this.autoCompleteList = autoCompleteList;
        this.completionAfterxChars = completionAfterxChars;

        this.addEventHandler(KeyEvent.KEY_RELEASED,new EventHandler<KeyEvent>() {
            public void handle(KeyEvent t) {

                String input = AutoCompleteTextField.this.getText();

                if (input.length() >= AutoCompleteTextField.this.completionAfterxChars){
                    for (String s : AutoCompleteTextField.this.autoCompleteList){

                        String match = s.substring(0, Math.min(input.length(), s.length()));

                        if(input.equals(match) || input.equals(match.toLowerCase())){
                            AutoCompleteTextField.this.appendText(s.substring((input.length()), Math.max(input.length(), s.length())));
                            AutoCompleteTextField.this.positionCaret(input.length());

                            int restOfInput = AutoCompleteTextField.this.getText().length() - input.length();
                            for (int i=0;i<restOfInput;i++)
                            {
                                AutoCompleteTextField.this.selectForward();
                            }
                            break;
                        }

                    }
                }

            }


        });

    }
}
