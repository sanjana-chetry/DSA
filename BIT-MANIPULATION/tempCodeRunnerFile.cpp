int getIthBit(int num,int i){
    int bitMask=1<<i;
    if(!(num & bitMask)){
        return 0;
    }
    else{
        return 1;
    }

}