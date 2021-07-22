// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef CHUCKRAM_QT_CHUCKRAMADDRESSVALIDATOR_H
#define CHUCKRAM_QT_CHUCKRAMADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ChuckramAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ChuckramAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Chuckram address widget validator, checks for a valid chuckram address.
 */
class ChuckramAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ChuckramAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // CHUCKRAM_QT_CHUCKRAMADDRESSVALIDATOR_H
