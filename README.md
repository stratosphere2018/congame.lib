# congame

――conioex.h に苦しめられる人たちを少しでも減らすために――

<!--
If able to translate into English or other languages, we request your help.
-->

## Introduction

このライブラリはコンソールでのゲーム開発を援助する目的で作られたものです。ゲームのアルゴリズムの勉強などにお役立てください。

## Setup

+ [Releases](https://github.com/stratosphere2018/congame.lib/releases) からお好みのバージョンを選択し、[こちら](https://qiita.com/jugemjugemu/items/39c5e90c9897fda12ccc)を参考にプロジェクトにインストールしてください。
+ このライブラリの関数を使いたいソースファイルにもしくはヘッダーファイルに、
  ```cpp
  #include "congame.h"
  ```
  を記述するとこのライブラリの関数群が使えるようになります。

## Usage

実装されている関数は、基本的にCongame名前空間下にあります。そのため使用する際は関数に`Congame::`と接頭するか、ソースファイルの序盤で`using namespace Congame;`を指定するようにしてください。

各関数についてより詳しくは[Wiki](https://github.com/stratosphere2018/congame.lib/wiki)をご覧ください。

# Licence

This package is released under the MIT License, see LICENSE.

このパッケージはMITライセンスに則って公開されています。

ご利用、改変など制限はしませんが、著作権は放棄しません。
