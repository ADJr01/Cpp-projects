namespace Algo{

    namespace rithm{
        template <class T>
        void merge(T *array,T *array1,int len,int len1,T *final){
            int i,j,k;
            i=j=k=0;
            while(i<len && j<len1){
                if(bool(array[i]<array1[j])){
                    final[k++]=array[i++];
                }else{
                    final[k++]=array1[j++];
                }
            }
            while (i<len){
                final[k++]=array[i++];
            }

            while (j<len1){
                final[k++]=array1[j++];
            }
        }

        template <class T>
        void MergeSort(T *array,int left,int n){
            if(n>=2){
                int mid=(left+n)/2;
                T *lArr=new T[mid];
                T *rArr=new T[n-mid];
                for (int i = 0; i < mid; i++) {
                    lArr[i]=array[i];
                }
                for (int j = 0; j < (n-mid); j++) {
                    rArr[j]=array[j+mid];
                }
                MergeSort(lArr,0,mid);
                MergeSort(rArr,mid,n-mid);
                merge(lArr,rArr,mid,n-mid,array);
            }
        }
    }
    template <class T>
    void srt(T *Array,int n){
        rithm::MergeSort(Array,0,n);
    }



}
