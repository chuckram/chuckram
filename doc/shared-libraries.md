Shared Libraries
================

## chuckramconsensus

The purpose of this library is to make the verification functionality that is critical to Chuckram's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `chuckramconsensus.h` located in  `src/script/chuckramconsensus.h`.

#### Version

`chuckramconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`chuckramconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `chuckramconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `chuckramconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `chuckramconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/chuckram/bips/blob/master/bip-0016.mediawiki)) subscripts
- `chuckramconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/chuckram/bips/blob/master/bip-0066.mediawiki)) compliance
- `chuckramconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/chuckram/bips/blob/master/bip-0147.mediawiki))
- `chuckramconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/chuckram/bips/blob/master/bip-0065.mediawiki))
- `chuckramconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/chuckram/bips/blob/master/bip-0112.mediawiki))
- `chuckramconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/chuckram/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `chuckramconsensus_ERR_OK` - No errors with input parameters *(see the return value of `chuckramconsensus_verify_script` for the verification status)*
- `chuckramconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `chuckramconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `chuckramconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `chuckramconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NChuckram](https://github.com/NicolasDorier/NChuckram/blob/master/NChuckram/Script.cs#L814) (.NET Bindings)
- [node-libchuckramconsensus](https://github.com/bitpay/node-libchuckramconsensus) (Node.js Bindings)
- [java-libchuckramconsensus](https://github.com/dexX7/java-libchuckramconsensus) (Java Bindings)
- [chuckramconsensus-php](https://github.com/Bit-Wasp/chuckramconsensus-php) (PHP Bindings)
