/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2008 Drexel University
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Joe Kopena (tjkopena@cs.drexel.edu)
 */

#ifndef TIME_DATA_CALCULATORS_H
#define TIME_DATA_CALCULATORS_H

#include "data-calculator.h"
#include "data-output-interface.h"

#include "ns3/nstime.h"

namespace ns3
{

//------------------------------------------------------------
//--------------------------------------------
/**
 * \ingroup stats
 *
 * Unfortunately, templating the base MinMaxAvgTotalCalculator to
 * operate over Time values isn't straightforward.  The main issues
 * are setting the maximum value, which can be worked around easily
 * as it done here, and dividing to get the average, which is not as
 * easily worked around.
 */
class TimeMinMaxAvgTotalCalculator : public DataCalculator
{
  public:
    TimeMinMaxAvgTotalCalculator();
    ~TimeMinMaxAvgTotalCalculator() override;

    /**
     * Register this type.
     * \return The TypeId.
     */
    static TypeId GetTypeId();

    /**
     * Updates all variables of TimeMinMaxAvgTotalCalculator
     * \param i value of type Time to use for updating the calculator
     */
    void Update(const Time i);

    /**
     * Outputs data based on the provided callback
     * \param callback
     */
    void Output(DataOutputCallback& callback) const override;

  protected:
    void DoDispose() override;

    uint32_t m_count; //!< Count value of TimeMinMaxAvgTotalCalculator
    Time m_total;     //!< Total value of TimeMinMaxAvgTotalCalculator
    Time m_min;       //!< Minimum value of TimeMinMaxAvgTotalCalculator
    Time m_max;       //!< Maximum value of TimeMinMaxAvgTotalCalculator

    // end class TimeMinMaxAvgTotalCalculator
};

// end namespace ns3
}; // namespace ns3

#endif /* TIME_DATA_CALCULATORS_H */
