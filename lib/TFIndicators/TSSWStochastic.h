/************************************************************************
 * Copyright(c) 2011, One Unified. All rights reserved.                 *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

#pragma once

#include "RunningMinMax.h"
#include "TimeSeriesSlidingWindow.h"

namespace ou { // One Unified
namespace tf { // TradeFrame

// 14,3,1 is standard  14 periods, 3 slow average, 1 fast average

class TSSWStochastic: public TimeSeriesSlidingWindow<TSSWStochastic, CQuote> {
  friend TimeSeriesSlidingWindow<TSSWStochastic, CQuote>;
public:
  TSSWStochastic( CQuotes* quotes, long WindowSizeSeconds );
  ~TSSWStochastic(void);
  double K( void ) const { return m_k; };
protected:
  void Add( const CQuote& quote );
  void Expire( const CQuote& quote );
  void PostUpdate( void );
private:
  long m_seconds;
  RunningMinMax m_minmax;

  double m_last;
  double m_k;
};

} // namespace tf
} // namespace ou