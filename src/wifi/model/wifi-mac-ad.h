/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2017 IMDEA Networks Institute
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
 * Author: Hany Assasa <hany.assasa@gmail.com>
 * ns-3 upstreaming process: Natale Patriciello <natale.patriciello@gmail.com>
 */
#pragma once

#include "wifi/model/wifi-mac.h"

namespace ns3 {

class WifiMacAd : public WifiMac
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);

  WifiMacAd();

  WifiPhyStandard GetCurrentstandard (void) const;

  typedef Callback<void, WifiPhyStandard, Mac48Address, bool> BandChangedCallback;
  void RegisterBandChangedCallback (BandChangedCallback callback);
  virtual void NotifyBandChanged (WifiPhyStandard, Mac48Address address, bool isInitiator) = 0;

  virtual void ConfigureStandard (WifiPhyStandard standard);

protected:
  /**
   * This method sets 802.11ad 60 GHz standards-compliant defaults for following attributes:
   * Sifs, Slot, EifsNoDifs, Pifs, CtsTimeout, and AckTimeout.
   */
  virtual void Configure80211ad (void);

  WifiPhyStandard m_standard;
  BandChangedCallback m_bandChangedCallback;
};

} // namespace ns3
