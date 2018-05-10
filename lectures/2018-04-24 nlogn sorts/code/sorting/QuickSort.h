#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "IndexedSort.h"
#include "../ADTs/Vector.h"
template <typename T>
class QuickSort : public IndexedSort<T>
{
private:
	int getPivot(Indexed<T> &data, int start_bound, int end_bound)
	{
		//assume best pivot is the starting index
		int pivot_index = start_bound;
		int mid_point = ((end_bound - start_bound) / 2) + start_bound;
		T start_value = data.getElementAt(start_bound);
		T mid_value = data.getElementAt(mid_point);
		T end_value = data.getElementAt(end_bound);

		//is the middle the best pivot?
		if (mid_value > start_value && mid_value < end_value)
		{
			pivot_index = mid_point;
		}
		else if (mid_value < start_value && mid_value > end_value)
		{
			pivot_index = mid_point;
		}

		//is end the best pivot?
		if (end_value > start_value && end_value < mid_value)
		{
			pivot_index = end_bound;
		}
		else if (end_value < start_value && end_value > mid_value)
		{
			pivot_index = end_bound;
		}
		return pivot_index;
	}
	void swap(Indexed<T> &data, int from, int to)
	{
		T temp = data.getElementAt(from);
		data.setElementAt(data.getElementAt(to), from);
		data.setElementAt(temp, to);
	}
	int findSmallerThan(Indexed<T> &data, T to_compare, int start_bound, int end_bound)
	{
		for (int i = end_bound; i >= start_bound; i--)
		{
			if (data.getElementAt(i) < to_compare)
			{
				return i;
			}
		}
		return start_bound - 1;
		
	}
	int findGreaterThan(Indexed<T> &data, T to_compare, int start_bound, int end_bound)
	{
		for (int i = start_bound; i <= end_bound; i++)
		{
			if (data.getElementAt(i) > to_compare)
			{
				return i;
			}
		}
		return end_bound + 1;
	}

	void sortHelper(Indexed<T> &data, int start_bound, int end_bound)
	{

	}


	void insertionSort(Indexed<T> &data, int start_bound, int end_bound)
	{
		for (int i = start_bound + 1; i <= end_bound; i++)
		{
			int j = i;
			while (j > 0 &&
				data.getElementAt(j - 1) > data.getElementAt(j)
				)
			{
				T temp = data.getElementAt(j - 1);
				T current = data.getElementAt(j);
				data.setElementAt(current, j - 1);
				data.setElementAt(temp, j);
				j--;
			}

		}
	}

public:
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		sortHelper(data, 0, data.getSize() - 1);
		return data;
	}

	
};

#endif