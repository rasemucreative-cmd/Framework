## このFrameworkは純粋なC言語を用いてcmd.exeでの描画や
## Androidに移植することも考えた実験的な試み

## 実装順(今はこれだけ)
	Application <-- ゲーム全体で利用される【今はTimerだけメンバに持つ】
	GameLoop	<-- ゲームの進行管理ゲーム内で使われるSceneと
					Applicationが持つタイマーとをつなぐ
	Timer		<-- ゲーム進行に必要なframeRateやfps,deltaTimeの
					管理、更新をする
	Scene		<-- ゲーム内でプレイヤーがプレイする場面やTitle,GameEnd
					といった実際ゲームでよく利用されるデータ群
