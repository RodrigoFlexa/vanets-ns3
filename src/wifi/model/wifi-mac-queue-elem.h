/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2022 Universita' degli Studi di Napoli Federico II
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
 * Author: Stefano Avallone <stavallo@unina.it>
 */

#ifndef WIFI_MAC_QUEUE_ELEM_H
#define WIFI_MAC_QUEUE_ELEM_H

#include "qos-utils.h"

#include "ns3/callback.h"
#include "ns3/nstime.h"

namespace ns3
{

class WifiMpdu;

/**
 * \ingroup wifi
 * Type of elements stored in a WifiMacQueue container.
 *
 * Such elements can be accessed by the WifiMacQueue (via iterators) and
 * by the WifiMpdu itself (via the iterator it stores).
 */
struct WifiMacQueueElem
{
    Ptr<WifiMpdu> mpdu;                    ///< MPDU stored by this element
    Time expiryTime;                       ///< expiry time of the MPDU (set by WifiMacQueue)
    AcIndex ac;                            ///< the Access Category associated with the queue
                                           ///< storing this element (set by WifiMacQueue)
    bool expired;                          ///< whether this MPDU has been marked as expired
    Callback<void, Ptr<WifiMpdu>> deleter; ///< reset the iterator stored by the MPDU

    /**
     * Constructor.
     * \param item the MPDU stored by this queue element
     */
    WifiMacQueueElem(Ptr<WifiMpdu> item);

    ~WifiMacQueueElem();
};

} // namespace ns3

#endif /* WIFI_MAC_QUEUE_ELEM_H */
