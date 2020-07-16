
public class ExpressionParser  extends Main{
    int real;
    int imaginar;
    public ExpressionParser(int real, int imaginar)
    {
        this.real=real;
        this.imaginar=imaginar;
    }
    static ExpressionParser expression(String in) {
        String findStr="*i";
        int lastIndex = 0;
        int count = 0;

        while((lastIndex = in.indexOf(findStr, lastIndex)) != -1) {
            count++;
            lastIndex += findStr.length() - 1;
        }
        if(count>1)
            return new ExpressionParser(0,0);
        String[] parts = in.split("[+-]");
        int re = 0, im = 0, pos = -1;
        for (String s : parts) {
            if (pos != -1) {
                s = in.charAt(pos) + s;
            } else {
                pos = 0;
                if ("".equals(s)) {
                    continue;
                }
            }
            pos += s.length();
            if (s.lastIndexOf('i') == -1) {
                if (!"+".equals(s) && !"-".equals(s)) {
                    re += Integer.parseInt(s);
                }
            } else {
                if(s.contains("*i"))
                    s = s.replace("*i", "");
                else if(s.length()==1) {
                    s = s.replace("i", "1*i");
                    s = s.replace("*i", "");
                }
                else {
                    //int[] fail = {0,0};
                    //return fail;
                    return new ExpressionParser(0,0);
                }
                if ("+".equals(s)) {
                    im++;
                } else if ("-".equals(s)) {
                    im--;
                } else {
                    im += Integer.parseInt(s);
                }
            }
        }
        ///Expression parser
        System.out.println("Real:\t" + re + "\nImag:\t" + im);
        /*int[] ans = new int[2];
        ans[0]=re;
        ans[1]=im;*/
        //return ans;
        return new ExpressionParser(re,im);
    }
}