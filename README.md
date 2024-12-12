# tantaka

「タンタカタンタンタンタンメン」のマルコフ連鎖です

## ビルド

ひとまず C の環境があれば動作するハズです。

```console
$ cc -o tantaka tantaka.c
```

## 出力例

```console
$ cc -o tantaka tantaka.c
$ for i in $(seq 10); do ./tantaka; sleep 1; done
タンタンメンメンタンタンタカタンタンメンタンタンタカタン
タンタンタンタンメンタンタンタン
タンタンタカタンタン
タン
タカタンタンメンメン
タンタカタンタン
タン
タンタカタンメンタンタン
タン
タンタンタンタカタンタンメン
```

## ライセンス

Unlicense
