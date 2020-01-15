package model;

public abstract class AbstractSorter extends SortingTask {
    protected int[] array;
    protected int length;

//    public AbstractSorter(SortingStrategy strategy, int[] array, int length) {
//        this.array = array;
//        this.length = length;
//    }
    AbstractSorter(int array[], int length){
        this.array = array;
        this.length = length;
    }
    void printArray()
    {
        for(int i = 0;i < length;i++)
            System.out.println(array[i]);
    }
    protected abstract void sort();
}
