#pragma once

#include <vector>

class Histogram {
  public:

    /* Constructors, destructor, assignment overload. */

    Histogram();
    ~Histogram();
    Histogram(const Histogram &h);
    Histogram& operator= (const Histogram &h);

    void Clear();                   // This clears the histogram's data
                                    // but retains the bin size if there

    bool   Set_Bin_Size(double bs); // Returns false if bs is <= 0, or if histogram is non empty.
    double Get_Bin_Size() const;    // Return -1 if the bin size has not been sent.
    bool   Add_Value(double d);     // Add a new value to the histogram.  Returns false if
                                    // the bin size has not been set.

    /* Get_Data() creates these two vectors.  There will be an element in each
       vector for every non-empty bin in the histogram.  bin_ids[i] will contain
       the "id" of the bin, where an id of 0 corresponds to values between [0 and
       Bin_Size), an id of 1 corresponds to values between [Bin_Size and Bin_Size*2),
       etc.  bin_ids will be sorted.  num_elts[i] contains the number of data points
       in bin i.
     */

    bool Get_Data(std::vector <int> &bin_ids, std::vector <int> &num_elts) const;

  protected:
    void *state;                  // This is so that whoever uses the data structure
                                  // does not know how it is implemented.
};
