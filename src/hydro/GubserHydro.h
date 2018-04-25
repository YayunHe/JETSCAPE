/*******************************************************************************
 * Copyright (c) The JETSCAPE Collaboration, 2017
 *
 * Modular, task-based framework
 * Intial Design: Joern Putschke, Kolja Kauder (Wayne State University)
 * For the full list of contributors see AUTHORS.

 * Report issues at https://github.com/JETSCAPE/JETSCAPE/issues
 * or via email to bugs.jetscape.org@gmail.com
 *
 * Distributed under the GNU General Public License 3.0 (GPLv3 or later).
 * See COPYING for details.
 ******************************************************************************/

#ifndef GUBSERHYDRO_H
#define GUBSERHYDRO_H

#include "JetScapeLogger.h"

#include "FluidDynamics.h"

using namespace Jetscape;

class GubserHydro: public FluidDynamics {
    // this is wrapper class for a simple brick
    // so that it can be used within the JETSCAPE framework
 private:
    double q;
    double e_0;
    double temperature(double e_local);

     
 public:
     GubserHydro();
     ~GubserHydro();

     void initialize_hydro(Parameter parameter_list);

     void evolve_hydro();

     void get_hydro_info(Jetscape::real t, Jetscape::real x, Jetscape::real y, Jetscape::real z,
			 std::unique_ptr<FluidCellInfo>& fluid_cell_info_ptr);

     void get_hypersurface(Jetscape::real T_cut, SurfaceCellInfo* surface_list_ptr) {};

};

#endif  // GUBSERHYDRO_H