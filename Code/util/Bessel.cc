//
// Copyright (C) University College London, 2007-2012, all rights reserved.
//
// This file is part of HemeLB and is CONFIDENTIAL. You may not work
// with, install, use, duplicate, modify, redistribute or share this
// file, or any part thereof, other than as allowed by any agreement
// specifically made by you with University College London.
//

#include "util/Bessel.h"

#include <cmath>
#include <cassert>
#include <iostream>

namespace hemelb
{
  namespace util
  {

    std::complex<double> BesselJ0ComplexArgument(const std::complex<double>& z, double tolSq)
    {
      // Zeroth term is 1
      std::complex<double> sum(1.0, 0.0);
      double fact = 1;
      std::complex<double> zSqOver4_pow(1.0, 0.0);
      std::complex<double> term(1.0, 0.0);

      unsigned i;
      for (i = 1; term.real() * term.real() + term.imag() * term.imag() > tolSq; ++i)
      {
        fact *= i;
        zSqOver4_pow *= -0.25 * z * z;
        term = zSqOver4_pow / (fact * fact);
        sum += term;
      }

      // If this assertion trips, it is likely that the zSqOver4_pow / (fact * fact) has become inf / inf
      /// @todo: #633 refactor
#ifdef HAVE_STD_ISNAN
      assert(!std::isnan(real(sum)) && !std::isnan(imag(sum)));
#endif
#ifdef HAVE_ISNAN
      assert(!isnan(real(sum)) && !isnan(imag(sum)));
#endif

      return sum;
    }
  }
}
