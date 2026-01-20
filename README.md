*This project has been created as part of the 42 curriculum by hwakatsu.*

# push_swap

## Description（概要）

**push_swap** は限られた命令セットのみを用いて、**スタックに格納された整数をできるだけ少ない操作数で昇順にソートする**ことを目的としています。

プログラムは整数のリストを引数として受け取り、それらを **スタック A** に格納します。
定義されたスタック操作のみを出力し、スタックを正しく整列させます。

本課題ではソートアルゴリズムの設計、データ構造の理解、操作コストの最適化が重要となります。

**ボーナス課題**では、**checker** という検証用プログラムを実装し、
与えられた操作列が実際にスタックを正しくソートできているかを判定します。

---

## Instructions（使い方・実行方法）

### 必要環境
- C コンパイラ（`cc`）
- GNU Make
- Unix 系 OS 環境

---

### コンパイル方法

`push_swap` のビルド：

```bash
make
ボーナス（checker）のビルド：

bash
コードをコピーする
make bonus
オブジェクトファイルの削除：

bash
コードをコピーする
make clean
バイナリおよびオブジェクトファイルの削除：

bash
コードをコピーする
make fclean
再ビルド：

bash
コードをコピーする
make re
実行方法
push_swap
bash
コードをコピーする
./push_swap <numbers>
例：

bash
コードをコピーする
./push_swap 3 2 1
出力例：

text
コードをコピーする
sa
rra
出力は 操作命令のみで構成され、
各命令は 改行（\n）で区切られ、それ以外の文字は一切出力されません。

checker（bonus）
bash
コードをコピーする
./checker <numbers>
操作命令を標準入力から与えます：

bash
コードをコピーする
./push_swap 3 2 1 | ./checker 3 2 1
出力結果：

OK — スタック A が昇順にソートされ、スタック B が空の場合

KO — 正しくソートされていない場合

Error — 不正な命令が入力された場合

使用可能な操作
sa, sb, ss — スタック先頭 2 要素を入れ替える

pa, pb — スタック間で要素を push

ra, rb, rr — スタックを上方向に回転

rra, rrb, rrr — スタックを下方向に回転

実装概要
データ構造
スタックは 連結リストとして実装

スタック A / B の先頭を「トップ」として扱う

入力チェック
数値以外の入力を拒否

int 型の範囲外の値を拒否

重複する値を検出しエラーとする

ソートアルゴリズム：Turk sort
本プロジェクトでは、要素数が多い場合のソート手法として
Turk sort（Turkish algorithm / Turk’s method） を採用しています。

Turk sort は push_swap において広く用いられる実装方針の一つで、
各要素について 最小操作コストで移動できる方法 を常に計算しながらソートを進める戦略です。

アプローチ概要
スタック A に存在する各要素に対して：

移動先の適切な位置

回転方向（ra, rra, rb, rrb, rr など）

操作回数（コスト）

を計算する

最もコストの低い要素 を選択し、スタック B へ移動

すべての要素をスタック B に移動した後、
最適な順序でスタック A に戻すことでソートを完成させる

この手法により：

無駄な回転操作を削減

操作回数を比較的安定して抑制

大規模入力に対しても効率的な挙動

を実現しています。

要素数ごとの処理分岐
5 要素以下

専用の最適化された小規模ソートロジックを使用

6 要素以上

Turk sort に基づく汎用ソートアルゴリズムを使用

Bonus（checker）
ボーナスの checker プログラムでは：

push_swap 本体で使用した スタック操作ロジックを再利用

操作命令の出力は行わず、命令の実行のみを行う

最終的にスタックが正しい状態かを検証する

Resources（参考資料）
アルゴリズム・データ構造
42 push_swap 公式 Subject PDF

ソートアルゴリズム一覧
https://en.wikipedia.org/wiki/Sorting_algorithm

スタック（データ構造）
https://en.wikipedia.org/wiki/Stack_(abstract_data_type)

計算量（Big-O 記法）
https://en.wikipedia.org/wiki/Big_O_notation

42 コミュニティ
42 intra 内でのディスカッション

push_swap 用ビジュアライザ／解析ツール（デバッグ・最適化用）

AI 利用に関する開示
本プロジェクトの開発にあたり、AI ツール（ChatGPT）を以下の目的で使用しました：

アルゴリズムおよびデータ構造の概念整理

バグの原因特定やロジックエラーの分析

Makefile 構成およびディレクトリ設計の相談

C 言語仕様やエッジケースに関する確認・理解の補助

yaml
コードをコピーする

---
