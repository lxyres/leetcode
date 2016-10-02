class Solution {
public:
    int romanToInt(string s) 
    {
        int num=0;
        const char *k=s.c_str();
        int status=0;
        //M 0 D 1 C 2 L 3 X 4 V 5 I 6
        while(*k!='\0')
        {
            switch(status)
            {
                case 0:
                    switch(*k)
                    {
                        case 'M':
                            num+=1000;
                            k++;
                            break;
                        case 'D':
                            num+=500;
                            k++;
                            status=2;
                            break;
                        case 'C':
                            num+=100;
                            k++;
                            status=2;
                            break;
                        case 'L':
                            num+=50;
                            k++;
                            status=4;
                            break;
                        case 'X':
                            num+=10;
                            k++;
                            status=4;
                            break;
                        case 'V':
                            num+=5;
                            k++;
                            status=6;
                            break;
                        default:
                            num+=1;
                            k++;
                            status=6;
                    }
                    break;
                case 2:
                    switch(*k)
                    {
                        case 'M':
                            num+=800;
                            k++;
                            break;
                        case 'D':
                            num+=300;
                            k++;
                            break;
                        case 'C':
                            num+=100;
                            k++;
                            break;
                        case 'L':
                            num+=50;
                            k++;
                            status=4;
                            break;
                        case 'X':
                            num+=10;
                            k++;
                            status=4;
                            break;
                        case 'V':
                            num+=5;
                            k++;
                            status=6;
                            break;
                        default:
                            num+=1;
                            k++;
                            status=6;
                    }
                    break;
                case 4:
                    switch(*k)
                    {
                        case 'C':
                            num+=80;
                            k++;
                            break;
                        case 'L':
                            num+=30;
                            k++;
                            break;
                        case 'X':
                            num+=10;
                            k++;
                            break;
                        case 'V':
                            num+=5;
                            k++;
                            status=6;
                            break;
                        default:
                            num+=1;
                            k++;
                            status=6;
                    }
                    break;
                default:
                    switch(*k)
                    {
                        case 'X':
                            num+=8;
                            k++;
                            break;
                        case 'V':
                            num+=3;
                            k++;
                            break;
                        default:
                            num+=1;
                            k++;
                    }
                    break;
            }
        }
        return num;
    }
};
