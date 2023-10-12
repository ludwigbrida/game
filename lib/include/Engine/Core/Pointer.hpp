#ifndef ENGINE_POINTER_HPP
#define ENGINE_POINTER_HPP

template <typename T>
class Pointer final {
public:
	Pointer() = default;

	explicit Pointer(T* ptr);

	Pointer(Pointer&& other) noexcept;

	Pointer(const Pointer& other) = delete;

	Pointer& operator=(const Pointer& other) = delete;

	Pointer& operator=(Pointer&& other) noexcept;

	T& operator*() const noexcept;

	T* operator->() const noexcept;

	explicit operator bool() const;

	~Pointer();

private:
	T* release() noexcept;

private:
	T* ptr = nullptr;
};

template <typename T>
Pointer<T>::Pointer(Pointer&& other) noexcept: ptr(other.release()) {}

template <typename T>
Pointer<T>::Pointer(T* ptr): ptr(ptr) {}

template <typename T>
Pointer<T>& Pointer<T>::operator=(Pointer&& other) noexcept {
	ptr = static_cast<T&&>(other.ptr);
	return *this;
}

template <typename T>
T& Pointer<T>::operator*() const noexcept {
	return *ptr;
}

template <typename T>
T* Pointer<T>::operator->() const noexcept {
	return ptr;
}

template <typename T>
Pointer<T>::operator bool() const {
	return ptr != nullptr;
}

template <typename T>
Pointer<T>::~Pointer() {
	delete ptr;
}

template <typename T>
T* Pointer<T>::release() noexcept {
	auto tmp = ptr;
	ptr = nullptr;
	return tmp;
}

#endif
