package model;

import model.AbstractSorter;

import java.util.List;

public class BubbleSort extends AbstractSorter {

    BubbleSort(int array[], int length) {
        super(array, length);
    }
    @Override
    public void sort() {
        int i, j, auxiliaryForSwitch;
        boolean swapped;
        for (i = 0; i < length - 1; i++) {
            swapped = false;
            for (j = 0; j < length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    auxiliaryForSwitch = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = auxiliaryForSwitch;
                    swapped = true;
                }
            }

            if (!swapped)
                break;
        }
    }
}
