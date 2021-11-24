//
//    rfnoc-hls-neuralnet: Vivado HLS code for neural-net building blocks
//
//    Copyright (C) 2017 EJ Kreinar
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef POLICY_H_
#define POLICY_H_

#ifndef __INTELFPGA_COMPILER__
#include "ac_int.h"
#include "ac_fixed.h"
#define hls_register
#else
#include "HLS/hls.h"
#include "HLS/ac_int.h"
#include "HLS/ac_fixed.h"
#endif

#include "parameters.h"

struct input_data {
    input_t input_2[N_INPUT_1_1];
};

struct output_data {
    result_t layer8_out[N_LAYER_8];
};


#ifndef __INTELFPGA_COMPILER__
output_data policy(
    input_data inputs,
    bool update_weights,
    weights_t* remote_weights
);
#else
//hls-fpga-machine-learning insert cpragmas
hls_max_concurrency(0)
hls_component_ii(128)
hls_scheduler_target_fmax_mhz(200)
component output_data policy(
    input_data inputs,
    bool load_weights,
    ihc::mm_master<weights_t, ihc::aspace<1>, ihc::dwidth<DWIDTH>, ihc::align<ALIGN> >  &remote_weights
);
#endif

#endif
