class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    
    // Complete the class
    int capacity;
    
    public:
    //Default constructor
    Polynomial() {
        degCoeff=new int[6];
        capacity=6;
        for(int i=0;i<capacity;i++) {
            degCoeff[i]=0;
        }
    }
    
    //Copy constructor
    Polynomial(Polynomial const &p) {
        this ->degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++) {
            this ->degCoeff[i]=p.degCoeff[i];
        }
        this ->capacity=p.capacity;
    }
    
    void operator=(Polynomial const &p) {
        this ->degCoeff=new int[p.capacity];
        for(int i=0;i<p.capacity;i++) {
            this ->degCoeff[i]=p.degCoeff[i];
        }
        this ->capacity=p.capacity;
    }
    
    void setCoefficient(int d,int coeff) {
        if(d>=capacity) {
            while(d>=capacity) {
                int *newDegCoeff=new int[2*capacity];
                for(int i=0;i<capacity;i++) {
                    newDegCoeff[i]=degCoeff[i];
                }
                for(int i=capacity;i<2*capacity;i++) {
                    newDegCoeff[i]=0;
                }
                delete [] degCoeff;
                degCoeff=newDegCoeff;
                capacity=2*capacity;
            }
        }
        degCoeff[d]=coeff;
    }
    
    Polynomial operator+(Polynomial const &p2) {
        Polynomial pnew;
        int j=min(capacity,p2.capacity);
        int i;
        for(i=0;i<j;i++) {
            pnew.degCoeff[i]=degCoeff[i]+p2.degCoeff[i];
        }
        if(i<capacity) {
            while(i<capacity) {
                pnew.setCoefficient(i,degCoeff[i]);
                i++;
            }
        }
        else if(i<p2.capacity) {
            while(i<p2.capacity) {
                pnew.setCoefficient(i,p2.degCoeff[i]);
                i++;
            }
        }
        return pnew;
    }
    
    Polynomial operator-(Polynomial const &p2) {
        Polynomial pnew;
        int j=min(capacity,p2.capacity);
        int i=0;
        for(i=0;i<j;i++) {
            pnew.degCoeff[i]=degCoeff[i]-p2.degCoeff[i];
        }
        if(i<capacity) {
            while(i<capacity) {
                pnew.setCoefficient(i,degCoeff[i]);
                i++;
            }
        }
        else if(i<p2.capacity) {
            while(i<p2.capacity) {
                pnew.setCoefficient(i,p2.degCoeff[i]);
                i++;
            }
        }
        return pnew;
    }
    
    Polynomial operator*(Polynomial const &p2) {
        Polynomial pnew;
        for(int i=0;i<capacity;i++) {
            for(int j=0;j<p2.capacity;j++) {
                if((i+j)<pnew.capacity) {
                    pnew.degCoeff[i+j]+=degCoeff[i]*p2.degCoeff[j];
                }
                else {
                    int *dc=new int[2*pnew.capacity];
                    for(int k=0;k<pnew.capacity;k++) {
                        dc[k]=pnew.degCoeff[k];
                    }
                    for(int k=pnew.capacity;k<2*pnew.capacity;k++) {
                        dc[k]=0;
                    }
                    delete [] pnew.degCoeff;
                    pnew.degCoeff=dc;
                    pnew.capacity=2*pnew.capacity;
                    pnew.degCoeff[i+j]=degCoeff[i]*p2.degCoeff[j];
                }
            }
        }
        return pnew;
    }

    void print() {
        for(int i=0;i<capacity;i++) {
            if(degCoeff[i]!=0) {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
};