#!/usr/bin/env bash
# Auto-generated test harness — run after cloning to verify the build.
set -uo pipefail
FAIL=0

echo "-- syntax/build check --"
if make && ./dark-stash --help 2>/dev/null || make; then echo "  ok"; else echo "  FAIL"; FAIL=1; fi

echo "-- functional check --"
OUT="$(make && echo 'Hello' | ./dark-stash 3 2>&1)"
if echo "$OUT" | grep -qF -- 'Khoor'; then
  echo "  ok   - contains: Khoor"
else
  echo "  FAIL - expected to contain: Khoor"
  echo "  got: $OUT"
  FAIL=1
fi

if [ "$FAIL" = "1" ]; then echo; echo "FAILED"; exit 1; fi
echo; echo "All tests passed."
