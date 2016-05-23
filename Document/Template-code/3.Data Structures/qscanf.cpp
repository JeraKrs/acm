void scanf_(int &num) {
    char in;
    bool neg=false;

    while(((in=getchar()) > '9' || in<'0') && in!='-') ;

    if(in=='-') {
        neg=true;
        while((in=getchar()) >'9' || in<'0');
    }

    num=in-'0';

    while(in=getchar(), in>='0'&&in<='9')
        num *= 10,num += in-'0';

	if (neg)
		num = -num;
}
