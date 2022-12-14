/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2007 Georgia Tech Research Corporation
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
 * Author:  George Riley <riley@ece.gatech.edu>
 * Adapted from original code in object.h by:
 * Authors: Gustavo Carneiro <gjcarneiro@gmail.com>,
 *          Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */

#include "ref-count-base.h"

#include "log.h"

/**
 * \file
 * \ingroup ptr
 * ns3::RefCountBase implementation.
 * \deprecated See \ref ns3::SimpleRefCount
 */

namespace ns3
{

NS_LOG_COMPONENT_DEFINE("RefCountBase");

RefCountBase::~RefCountBase()
{
    NS_LOG_FUNCTION(this);
}

} // namespace ns3
