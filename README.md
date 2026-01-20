*This project has been created as part of the 42 curriculum by hwakatsu.*

# push_swap

## Description

**push_swap** は 42 カリキュラムのアルゴリズム課題です。
限られた命令セットのみを使用し、スタックに格納された整数をできるだけ少ない操作数で昇順にソートすることを目的としています。

整数はスタック A に格納され、`sa`, `pb`, `ra` などの決められた操作のみを出力することでソートを行います。

Bonus では、与えられた操作列が正しくソートを行えているかを検証する **checker** プログラムを実装しています。

---

## Instructions

### Build

make
make bonus

make clean
make fclean
make re

---

### Usage

#### push_swap

./push_swap <numbers>

例：
./push_swap 3 2 1

出力は操作命令のみで、各命令は改行（`\n`）で区切られます。

---

#### checker（bonus）

./checker <numbers>

例：
./push_swap 3 2 1 | ./checker 3 2 1

出力結果：
- OK：スタック A が昇順で、スタック B が空
- KO：正しくソートされていない
- Error：不正な命令

---

## Allowed Operations

- sa, sb, ss — swap
- pa, pb — push
- ra, rb, rr — rotate
- rra, rrb, rrr — reverse rotate

---

## Implementation

- スタックは連結リストで実装
- 入力値に対して以下を検証：
  - 数値以外の入力
  - int の範囲外の値
  - 重複値

### Sorting Algorithm: Turk sort

6 要素以上のソートには **Turk sort（Turkish algorithm / Turk’s method）** を使用しています。

各要素について、移動先・回転方向・操作コストを計算し、
最小コストの要素を優先的に移動することで、無駄な回転を抑えた効率的なソートを行います。

- 5 要素以下：専用の最適化ロジック
- 6 要素以上：Turk sort

---

## Bonus (checker)

checker では、push_swap と同じスタック操作ロジックを使用しつつ、
操作命令の出力を行わず、命令の実行と最終状態の検証のみを行います。

---

## Resources

- 42 push_swap Subject PDF
- https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
- https://medium.com/@ayogun/push-swap-c1f5d2d41e97

---

## AI Usage Disclosure

本プロジェクトでは、AI（ChatGPT）を以下の用途で使用しました：

- アルゴリズム・データ構造の理解補助
- バグ解析およびロジック検証
- Makefile やディレクトリ構成の整理
- C 言語仕様・エッジケースの確認
