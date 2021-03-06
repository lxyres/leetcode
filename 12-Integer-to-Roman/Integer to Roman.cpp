class Solution {
public:
    string intToRoman(int num) 
    {
        string s;
        const string symbol[]={"I","II","III","IV","V","VI","VII","VIII","IX"};
        if(num>=1000)
        {
            num-=1000;
            s+="M";
            while(num>=1000)
            {
                num-=1000;
                s+="M";
            }
        }
        if(num>=900)
        {
            num-=900;
            s+="CM";
        }
        if(num>=500)
        {
            num-=500;
            s+="D";
        }
        if(num>=400)
        {
            num-=400;
            s+="CD";
        }
        if(num>=100)
        {
            num-=100;
            s+="C";
            while(num>=100)
            {
                num-=100;
                s+="C";
            }
        }
        if(num>=90)
        {
            num-=90;
            s+="XC";
        }
        if(num>=50)
        {
            num-=50;
            s+="L";
        }
        if(num>=40)
        {
            num-=40;
            s+="XL";
        }
        if(num>=10)
        {
            num-=10;
            s+="X";
            while(num>=10)
            {
                num-=10;
                s+="X";
            }
        }
        if(num>0)s+=symbol[num-1];
        return s;
    }
};
