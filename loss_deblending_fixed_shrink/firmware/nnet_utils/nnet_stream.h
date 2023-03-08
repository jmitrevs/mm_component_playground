#ifndef NNET_CLONE_H
#define NNET_CLONE_H

#include "nnet_common.h"

namespace nnet {

struct broadcast_config {
  static const unsigned in_height = 10;
  static const unsigned in_width = 10;
  static const unsigned n_chan = 1;
  static const unsigned n_dupl = 2;
};

template<class data_T, unsigned int data_N, class res_T, unsigned int res_N1, unsigned int res_N2, int N>
void clone_stream(stream<data_T, data_N> &data, stream<res_T, res_N1> &res1, stream<res_T, res_N2> &res2) {
    CloneLoop: 
    #pragma ii 1
    for (int i = 0; i < N / data_T::size; i++) {
        data_T in_data = data.read();
        res_T out_data1;
        res_T out_data2;
        
        ClonePack:
        #pragma unroll
        for (int j = 0; j < data_T::size; j++) {
            out_data1[j] = in_data[j];
            out_data2[j] = in_data[j];
        }

        res1.write(out_data1);
        res2.write(out_data2);
    }
}

template<class data_T, unsigned int data_N, class res_T, unsigned int res_N1, unsigned int res_N2, unsigned int res_N3, int N>
void clone_stream(stream<data_T, data_N> &data, stream<res_T, res_N1> &res1, stream<res_T, res_N2> &res2, stream<res_T, res_N3> &res3) {
    CloneLoop: 
    #pragma ii 1
    for (int i = 0; i < N / data_T::size; i++) {
        data_T in_data = data.read();
        res_T out_data1;
        res_T out_data2;
        res_T out_data3;

        ClonePack:
        #pragma unroll
        for (int j = 0; j < data_T::size; j++) {
            out_data1[j] = in_data[j];
            out_data2[j] = in_data[j];
            out_data3[j] = in_data[j];
        }

        res1.write(out_data1);
        res2.write(out_data2);
        res3.write(out_data3);
    }
}

}

#endif
