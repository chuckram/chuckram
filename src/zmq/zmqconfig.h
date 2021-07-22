// Copyright (c) 2014-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CHUCKRAM_ZMQ_ZMQCONFIG_H
#define CHUCKRAM_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include <config/chuckram-config.h>
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include <primitives/block.h>
#include <primitives/transaction.h>

void zmqError(const char *str);

#endif // CHUCKRAM_ZMQ_ZMQCONFIG_H
