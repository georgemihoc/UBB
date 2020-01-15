package model;

public class SortingTask extends Task {
    private AbstractSorter instanceSorter;
    private SortingStrategy strategy;
    int array[];
    int length;

    public SortingTask(SortingStrategy strategy, int array[], int length) {
        this.strategy = strategy;
        this.array = array;
        this.length =length;
        switch (strategy) {
            case BubbleSort:
                instanceSorter = new BubbleSort(array, length);
                break;
            case QuickSort:
                instanceSorter = new QuickSort(array, length);
                break;
        }
    }

    public SortingTask() {
    }

    public void execute(){
        instanceSorter.sort();
        instanceSorter.printArray();
    }
}
