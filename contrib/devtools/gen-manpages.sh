#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

CHUCKRAMD=${CHUCKRAMD:-$BINDIR/chuckramd}
CHUCKRAMCLI=${CHUCKRAMCLI:-$BINDIR/chuckram-cli}
CHUCKRAMTX=${CHUCKRAMTX:-$BINDIR/chuckram-tx}
CHUCKRAMQT=${CHUCKRAMQT:-$BINDIR/qt/chuckram-qt}

[ ! -x $CHUCKRAMD ] && echo "$CHUCKRAMD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
CKMVER=($($CHUCKRAMCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for chuckramd if --version-string is not set,
# but has different outcomes for chuckram-qt and chuckram-cli.
echo "[COPYRIGHT]" > footer.h2m
$CHUCKRAMD --version | sed -n '1!p' >> footer.h2m

for cmd in $CHUCKRAMD $CHUCKRAMCLI $CHUCKRAMTX $CHUCKRAMQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${CKMVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${CKMVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
