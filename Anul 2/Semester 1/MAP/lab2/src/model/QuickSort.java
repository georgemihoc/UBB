package model;

import model.AbstractSorter;

import java.util.List;

public class QuickSort extends AbstractSorter {

    QuickSort(int array[], int length) {
        super(array, length);
    }

    private int partition(int array[], int low, int high)
    {
        int pivot = array[high];
        int i = (low-1);
        for (int j=low; j<high; j++)
        {
            if (array[j] < pivot)
            {
                i++;

                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int auxiliaryForSwitch = array[i+1];
        array[i+1] = array[high];
        array[high] = auxiliaryForSwitch;

        return i+1;
    }

    private void recursiveSort(int array[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(array, low, high);
            recursiveSort(array, low, pi-1);
            recursiveSort(array, pi+1, high);
        }
    }

    @Override
    public void sort() {
        recursiveSort(array, 0, length - 1);
    }
}