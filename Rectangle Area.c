int computePublicLen(int a1,int a2,int b1,int b2){
    if(b1>=a1&&b1<=a2&&b2>=a1&&b2<=a2){
        return b2-b1;
    }else if(b1>=a1&&b1<=a2){
        return a2-b1;
    }else if(b2>=a1&&b2<=a2){
        return b2-a1;
    }else{
        return 0;
    }
}

int computePublic(int aX1,int aY1,int aX2,int aY2,int bX1,int bY1,int bX2,int bY2){
    int xLen,yLen;
    xLen=computePublicLen(aX1,aX2,bX1,bX2);
    if(xLen==0){
        xLen=computePublicLen(bX1,bX2,aX1,aX2);
    }
    yLen=computePublicLen(aY1,aY2,bY1,bY2);
    if(yLen==0){
        yLen=computePublicLen(bY1,bY2,aY1,aY2);
    }
    
    return xLen*yLen;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int ret;
    if((ret=computePublic(A,B,C,D,E,F,G,H))!=0){
        return (C-A)*(D-B)-ret+(G-E)*(H-F);
    }
    return (C-A)*(D-B)+(G-E)*(H-F);
}
